#if(SEMIHOSTING == 0)
/* Includes */
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>

/* Variables */
//#undef errno
extern int errno;
extern int __io_putchar(int ch) __attribute__((weak));
extern int __io_getchar(void) __attribute__((weak));

register char * stack_ptr asm("sp");

char *__env[1] = { 0 };
char **environ = __env;



/* Functions */
void initialise_monitor_handles()
{
}

int _getpid(void)
{
	return 1;
}

int _kill(int pid, int sig)
{
	pid =pid; sig = sig;
	errno = EINVAL;
	return -1;
}

void _exit (int status)
{
	status = status;
	_kill(status, -1);
	while (1) {}		/* Make sure we hang here */
}

__attribute__((weak)) int _read(int file, char *ptr, int len)
{
	int DataIdx;
    file = file;
	for (DataIdx = 0; DataIdx < len; DataIdx++)
	{
		*ptr++ = __io_getchar();
	}

return len;
}

__attribute__((weak)) int _write(int file, char *ptr, int len)
{
	int DataIdx;
    file = file;
	for (DataIdx = 0; DataIdx < len; DataIdx++)
	{
		__io_putchar(*ptr++);
		//ITM_SendChar(*ptr++);
	}
	return len;
}

int _close(int file)
{
	file = file;
	return -1;
}


int _fstat(int file, struct stat *st)
{
	file = file;
	st->st_mode = S_IFCHR;
	return 0;
}

int _isatty(int file)
{
	file = file;
	return 1;
}

int _lseek(int file, int ptr, int dir)
{
	file = file;ptr=ptr;dir = dir;
	return 0;
}

int _open(char *path, int flags, ...)
{
	flags = flags;
	*path = 0;
	/* Pretend like we always fail */
	return -1;
}

int _wait(int *status)
{
	*status = *status;
	errno = ECHILD;
	return -1;
}

int _unlink(char *name)
{
	*name = 0;
	errno = ENOENT;
	return -1;
}

int _times(struct tms *buf)
{
	buf ->tms_utime = 0;
	return -1;
}

int _stat(char *file, struct stat *st)
{
	*file = 0;
	st->st_mode = S_IFCHR;
	return 0;
}

int _link(char *old, char *new)
{
	*old = *new = 0;
	errno = EMLINK;
	return -1;
}

int _fork(void)
{
	errno = EAGAIN;
	return -1;
}

int _execve(char *name, char **argv, char **env)
{
	*name = 0;
	*argv = (char *)(NULL);
	*env = (char *)(NULL);
	errno = ENOMEM;
	return -1;
}

/**
 _sbrk
 Increase program data space. Malloc and related functions depend on this
**/
caddr_t _sbrk(int incr)
{
	extern char end asm("end");
	static char *heap_end;
	char *prev_heap_end;

	if (heap_end == 0)
		heap_end = &end;

	prev_heap_end = heap_end;
	if (heap_end + incr > stack_ptr)
	{
		errno = ENOMEM;
		return (caddr_t) -1;
	}

	heap_end += incr;

	return (caddr_t) prev_heap_end;
}
#endif
