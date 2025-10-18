#ifndef LIB_H
#define LIB_H
// gcc -std=c99 -Wall main.c lib.c -o perf_test -lrt
#include <stdint.h>
#include <stdbool.h>

/* Participant Indices */
#define PARTICIPANT_QIAN	0
#define PARTICIPANT_YU		1
#define NUM_PARTICIPANTS	2

/* Configuration */
#define MAX_QUESTIONS		100
#define EXEC_COUNT		100000L

/*
 * perf_exec - Execute a test function and record its time.
 * @idx:	The question index.
 * @name:	The name of the question.
 * @func:	The test function pointer.
 * @record_time: Whether to record and aggregate the time (true) or run once (false).
 */
void perf_exec(uint8_t idx, const char *name, void (*func)(void),
	       bool record_time);

/*
 * perf_judge - Print the precisely aligned performance results table using ANSI CUP.
 */
void perf_judge(void);

/*
 * perf_start - Clears the terminal screen and moves cursor to home.
 */
void perf_start(void);

#endif /* LIB_H */