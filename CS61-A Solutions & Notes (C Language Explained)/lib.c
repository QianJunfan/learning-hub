#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "lib.h"

/* Hidden Global Data (static to this file) */
static uint64_t total_time[NUM_PARTICIPANTS][MAX_QUESTIONS];
static const char *question_names[MAX_QUESTIONS];
static uint8_t current_max_idx;

/*
 * get_time_us - High-Precision Timer (Linux/POSIX)
 *
 * Returns the current time in microseconds.
 */
static uint64_t get_time_us(void)
{
        struct timespec ts;

        if (clock_gettime(CLOCK_MONOTONIC_RAW, &ts) == -1) {
                perror("clock_gettime");
                return 0;
        }

        return (uint64_t)ts.tv_sec * 1000000L + (uint64_t)ts.tv_nsec / 1000L;
}

/*
 * perf_exec - Execute a test function and record its time.
 */
void perf_exec(uint8_t idx, const char *name, void (*func)(void),
               bool record_time)
{
        long count;
        uint64_t start_time, end_time, elapsed_us;
        int participant_idx = -1;
        long i;

        if (idx >= MAX_QUESTIONS) {
                fprintf(stderr, "Error: Question index %u is out of bounds.\n",
                        idx);
                return;
        }

        if (question_names[idx] == NULL) {
                question_names[idx] = name;
                if (idx >= current_max_idx)
                        current_max_idx = idx + 1;
        }

        count = record_time ? EXEC_COUNT : 1L;

        start_time = get_time_us();

        for (i = 0; i < count; ++i)
                func();

        end_time = get_time_us();
        elapsed_us = end_time - start_time;

        if (!record_time)
                return;

        /* Determine participant index */
        if (total_time[PARTICIPANT_QIAN][idx] == 0)
                participant_idx = PARTICIPANT_QIAN;
        else if (total_time[PARTICIPANT_YU][idx] == 0)
                participant_idx = PARTICIPANT_YU;

        if (participant_idx != -1)
                total_time[participant_idx][idx] = elapsed_us;
}

/*
 * perf_judge - Print the precisely aligned performance results table.
 */
void perf_judge(void)
{
        uint64_t overall_total_time[NUM_PARTICIPANTS] = {0};
        const char *names[] = {"QIAN JUNFAN", "YU LAN"};
        int current_line = 3; 
        uint8_t i;

        /* Define fixed column start positions (chars from left) */
        const int COL_IDX = 1;
        const int COL_QIAN = 15;
        const int COL_YU = 40;
        const int COL_NAME = 65;

        /* CUP: Cursor Position \033[Y;XH */
        printf("\033[%d;%dH i love you 3000 times... \n", 1, 1);

        /* Print header */
        printf("\033[%d;%dH%-10s \033[%d;%dH%-10s \033[%d;%dH%-10s \033[%d;%dH%-20s\n", 
               current_line, COL_IDX, " question", 
               current_line, COL_QIAN, names[PARTICIPANT_QIAN], 
               current_line, COL_YU, names[PARTICIPANT_YU], 
               current_line, COL_NAME, "question name");
        current_line++;

        /* Print Separator Line */
        printf("\033[%d;%dH----------------------------------------------------------------------------------\n",
               current_line, 1);
        current_line++;


        for (i = 0; i < current_max_idx; ++i) {
                uint64_t qian_time = total_time[PARTICIPANT_QIAN][i];
                uint64_t yulan_time = total_time[PARTICIPANT_YU][i];

                overall_total_time[PARTICIPANT_QIAN] += qian_time;
                overall_total_time[PARTICIPANT_YU] += yulan_time;

                uint64_t qian_ms = (qian_time + 500) / 1000;
                uint64_t yulan_ms = (yulan_time + 500) / 1000;

                char qian_raw_ms[20], yulan_raw_ms[20];

                if (qian_time > 0 && yulan_time > 0) {
                        if (qian_ms == 0)
                                qian_ms = 1; 
                        if (yulan_ms == 0)
                                yulan_ms = 1;

                        snprintf(qian_raw_ms, 20, "%llums", (long long)qian_ms);
                        snprintf(yulan_raw_ms, 20, "%llums", (long long)yulan_ms);
                } else if (qian_time > 0) {
                        snprintf(qian_raw_ms, 20, "%llums",
                                 (long long)qian_ms == 0 ? 1 : (long long)qian_ms);
                        strcpy(yulan_raw_ms, "N/A");
                } else if (yulan_time > 0) {
                        snprintf(yulan_raw_ms, 20, "%llums",
                                 (long long)yulan_ms == 0 ? 1 : (long long)yulan_ms);
                        strcpy(qian_raw_ms, "N/A");
                } else {
                        strcpy(qian_raw_ms, "N/A");
                        strcpy(yulan_raw_ms, "N/A");
                }

                /* Print single question result using CUP positioning */
                printf("\033[%d;%dH q%-2d", current_line, COL_IDX, i + 1);

                /* Print QIAN's time */
                printf("\033[%d;%dH%s", current_line, COL_QIAN, qian_raw_ms);

                /* Print YU's time */
                printf("\033[%d;%dH%s", current_line, COL_YU, yulan_raw_ms);

                /* Print Question Name */
                printf("\033[%d;%dH%-20s\n", current_line, COL_NAME,
                       question_names[i] ? question_names[i] : "unknown");

                current_line++;
        }

        /* Print Separator Line */
        printf("\033[%d;%dH----------------------------------------------------------------------------------\n",
               current_line, 1);
        current_line++;

        /* Print total scores */
        uint64_t qian_total_ms = (overall_total_time[PARTICIPANT_QIAN] + 500) / 1000;
        uint64_t yulan_total_ms = (overall_total_time[PARTICIPANT_YU] + 500) / 1000;

        /* Print Total row using CUP positioning */
        printf("\033[%d;%dH%-10s", current_line, COL_IDX, " total"); 
        printf("\033[%d;%dH%llums", current_line, COL_QIAN, (long long)qian_total_ms); 
        printf("\033[%d;%dH%llums", current_line, COL_YU, (long long)yulan_total_ms);
        printf("\033[%d;%dH%-20s\n", current_line, COL_NAME, "");

        fflush(stdout);
}

/*
 * perf_start - Clears the terminal screen and moves cursor to home.
 */
void perf_start(void)
{
        /* Clear the entire terminal screen (\033[2J) */
        printf("\033[2J");
        /* Move cursor to home position (\033[1;1H) */
        printf("\033[1;1H");
}