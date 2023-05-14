
# Allowed functions
- readline

       readline will read a line from the terminal and return it, using
       prompt as a prompt.  If prompt is NULL or the empty string, no
       prompt is issued.  The line returned is allocated with malloc(3);
       the caller must free it when finished.  The line returned has the
       final newline removed, so only the text of the line remains.

       readline(const char *prompt);

- rl_clear_history:

        Function: void rl_clear_history (void)
        Clear the history list by deleting all of the entries, in the same
        manner   as the History library’s clear_history() function. 
        This differs from clear_history because it frees private data Readline
        saves in the history list. 

- rl_on_new_line:
        
        Function: int rl_on_new_line (void)
        Tell the update functions that we have moved onto a new (empty) line, usually
        after outputting a newline. 

- rl_replace_line:

        Function: void rl_replace_line (const char *text, int clear_undo)
        Replace the contents of rl_line_buffer with text. The point and mark are
        preserved, if possible. If clear_undo is non-zero, the undo list associated 
        with the current line is cleared. 
- rl_redisplay:

        Function: void rl_redisplay (void)
        Change what’s displayed on the screen to reflect the current contents of
        rl_line_buffer.

  [rl library](https://tiswww.case.edu/php/chet/readline/readline.html)


- add_history:

        Function: void add_history (char *string)
        Place string at the end of the history list. The associated data field (if 
        any) is set to NULL. 

- printf, malloc, free, write, open, read, close, exit:
        
        old friends

- access:

        int access(const char *pathname, int mode);
        access() checks whether the calling process can access the file pathname.
        If pathname is a symbolic link, it is dereferenced. 
        
    [access manual](https://linux.die.net/man/2/access)

- fork:
        
       fork() creates a new process by duplicating the calling process.
       The new process is referred to as the child process.  The calling
       process is referred to as the parent process.

    [fork manual](https://man7.org/linux/man-pages/man2/fork.2.html)

- wait, waitpid:
        
        #include <sys/types.h>
        #include <sys/wait.h>
        
        wait() and waitpid()
        The wait() system call suspends execution of the calling thread
        until one of its children terminates.  The call wait(&wstatus) is
        equivalent to:

           waitpid(-1, &wstatus, 0);

        The waitpid() system call suspends execution of the calling
        thread until a child specified by pid argument has changed state.
        By default, waitpid() waits only for terminated children, but
        this behavior is modifiable via the options argument, as
        described below.

    [wait manual](https://man7.org/linux/man-pages/man2/wait.2.html)

- wait3, wait4:

        Description
        These functions are obsolete; use waitpid(2) or waitid(2) in new programs.
        The wait3() and wait4() system calls are similar to waitpid(2), but
        additionally return resource usage information about the child in the 
        tructure pointed to by rusage.

- signal:

        WARNING: the behavior of signal() varies across UNIX versions,
        and has also varied historically across different versions of
        Linux.  Avoid its use: use sigaction(2) instead.  See Portability
        below.
    
- sigaction:
        
        #include <signal.h>
        int sigaction(int signum, const struct sigaction *restrict act,
                     struct sigaction *restrict oldact);
        The sigaction() system call is used to change the action taken by
        a process on receipt of a specific signal.  (See signal(7) for an
        overview of signals.)
        signum specifies the signal and can be any valid signal except
        SIGKILL and SIGSTOP.
    [sigaction manual](https://man7.org/linux/man-pages/man2/sigaction.2.html)

- sigemptyset:
        
        #include <signal.h>
        int sigemptyset(sigset_t *set);

        The sigemptyset() function initializes the signal set pointed to
        by set, such that all signals defined in POSIX.1‐2008 are
        excluded.
    [sigemptyset manual](https://man7.org/linux/man-pages/man3/sigemptyset.3p.html)

- sigaddset:

        #include <signal.h>
        int sigaddset(sigset_t *set, int signo);

        The sigaddset() function adds the individual signal specified by
        the signo to the signal set pointed to by set.

        Applications shall call either sigemptyset() or sigfillset() at
        least once for each object of type sigset_t prior to any other
        use of that object. If such an object is not initialized in this
        way, but is nonetheless supplied as an argument to any of
        pthread_sigmask(), sigaction(), sigaddset(), sigdelset(),
        sigismember(), sigpending(), sigprocmask(), sigsuspend(),
        sigtimedwait(), sigwait(), or sigwaitinfo(), the results are
        undefined.
    [sigaddset manual](https://man7.org/linux/man-pages/man3/sigaddset.3p.html)

- kill:
       
        #include <signal.h>
        int kill(pid_t pid, int sig);
       
        The kill() system call can be used to send any signal to any
        process group or process.

    [kill manual](https://man7.org/linux/man-pages/man2/kill.2.html)

- getcwd:

        #include <unistd.h>
        char *getcwd(char *buf, size_t size);

        These functions return a null-terminated string containing an
        absolute pathname that is the current working directory of the
        calling process.  The pathname is returned as the function result
        and via the argument buf, if present.

    [getcwd manual](https://man7.org/linux/man-pages/man3/sigaddset.3p.html)

 - chdir:

        #include <unistd.h>
        int chdir(const char *path);

        chdir() changes the current working directory of the calling
        process to the directory specified in path.

    [chdir manual](https://man7.org/linux/man-pages/man2/fchdir.2.html)

 - stat, lstat, fstat:

        #include <sys/types.h>
        #include <sys/stat.h>
        #include <unistd.h>

        int stat(const char *path, struct stat *buf);
        int fstat(int fd, struct stat *buf);
        int lstat(const char *path, struct stat *buf); 
        
        These functions return information about a file. No permissions are
        required on the file itself, but-in the case of stat() and lstat() - 
        execute (search) permission is required on all of the directories in path 
        that lead to the file.

        stat() stats the file pointed to by path and fills in buf.
        lstat() is identical to stat(), except that if path is a symbolic link,
                then the link itself is stat-ed, not the file that it refers to.
        fstat() is identical to stat(), except that the file to be stat-ed is
                specified by the file descriptor fd.

        All of these system calls return a stat structure, see in manual
   [stats manual](https://man7.org/linux/man-pages/man2/lstat.2.html)

 - fields: 
        
        not found!

 - unlink: 

        #include <unistd.h>
        int unlink(const char *pathname);

        unlink() deletes a name from the filesystem.  If that name was
        the last link to a file and no processes have the file open, the
        file is deleted and the space it was using is made available for
        reuse.

   [unlink manual](https://man7.org/linux/man-pages/man2/unlink.2.html)

 - execve:

        #include <unistd.h>

        int execve(const char *pathname, char *const argv[],
                  char *const envp[]);
        execve() executes the program referred to by pathname.  This
        causes the program that is currently being run by the calling
        process to be replaced with a new program, with newly initialized
        stack, heap, and (initialized and uninitialized) data segments.
   [execve manual](https://man7.org/linux/man-pages/man2/execve.2.html)

 - dup, dup2:

        #include <unistd.h>
        int dup(int oldfd);
        int dup2(int oldfd, int newfd);

        The dup() system call allocates a new file descriptor that refers
        to the same open file description as the descriptor oldfd.  (For
        an explanation of open file descriptions, see open(2).)  The new
        file descriptor number is guaranteed to be the lowest-numbered
        file descriptor that was unused in the calling process.

        The dup2() system call performs the same task as dup(), but
        instead of using the lowest-numbered unused file descriptor, it
        uses the file descriptor number specified in newfd.  In other
        words, the file descriptor newfd is adjusted so that it now
        refers to the same open file description as oldfd.

   [dups manual](https://man7.org/linux/man-pages/man2/dup.2.html)

 - pipe:

        #include <unistd.h>
        int pipe(int pipefd[2]);
        
        pipe() creates a pipe, a unidirectional data channel that can be
        used for interprocess communication.  The array pipefd is used to
        return two file descriptors referring to the ends of the pipe.
        pipefd[0] refers to the read end of the pipe.  pipefd[1] refers
        to the write end of the pipe.  Data written to the write end of
        the pipe is buffered by the kernel until it is read from the read
        end of the pipe.
   [pipe manual](https://man7.org/linux/man-pages/man2/pipe.2.html)

 - opendir:
        
        #include <sys/types.h>
        #include <dirent.h>

        The opendir() function opens a directory stream corresponding to
        the directory name, and returns a pointer to the directory
        stream.  The stream is positioned at the first entry in the
        directory.

   [opendir manual](https://man7.org/linux/man-pages/man3/opendir.3.html)

 - readdir:

        #include <dirent.h>
        struct dirent *readdir(DIR *dirp);

        The readdir() function returns a pointer to a dirent structure
        representing the next directory entry in the directory stream
        pointed to by dirp.  It returns NULL on reaching the end of the
        directory stream or if an error occurred.

        In the glibc implementation, the dirent structure is defined as
        follows:
           struct dirent {
               ino_t          d_ino;       /* Inode number */
               off_t          d_off;       /* Not an offset; see below */
               unsigned short d_reclen;    /* Length of this record */
               unsigned char  d_type;      /* Type of file; not supported
                                              by all filesystem types */
               char           d_name[256]; /* Null-terminated filename */
           };

   [readdir manual](https://man7.org/linux/man-pages/man3/readdir.3.html)

 - closedir:

        #include <sys/types.h>
        #include <dirent.h>
        int closedir(DIR *dirp);

        The closedir() function closes the directory stream associated
        with dirp.  A successful call to closedir() also closes the
        underlying file descriptor associated with dirp.  The directory
        stream descriptor dirp is not available after this call.

   [closedir manual](https://man7.org/linux/man-pages/man3/closedir.3.html)

 - strerror:

        #include <string.h>
        char *strerror(int errnum);

        The strerror() function returns a pointer to a string that
        describes the error code passed in the argument errnum, possibly
        using the LC_MESSAGES part of the current locale to select the
        appropriate language.  (For example, if errnum is EINVAL, the
        returned description will be "Invalid argument".)  This string
        must not be modified by the application, but may be modified by a
        subsequent call to strerror() or strerror_l().  No other library
        function, including perror(3), will modify this string.

   [strerror manual](https://man7.org/linux/man-pages/man3/strerror.3.html)

 - perror:

        #include <stdio.h>
        #include <errno.h>
        void perror(const char *s);

        The perror() function produces a message on standard error
        describing the last error encountered during a call to a system
        or library function.

   [perror manual](https://man7.org/linux/man-pages/man3/perror.3.html)

 - isatty:

        #include <unistd.h>
        int isatty(int fd);

        The isatty() function tests whether fd is an open file descriptor
        referring to a terminal.

   [isatty manual](https://man7.org/linux/man-pages/man3/isatty.3.html)

 - ttyname:
        
        #include <unistd.h>
        char *ttyname(int fd);

        The function ttyname() returns a pointer to the null-terminated
        pathname of the terminal device that is open on the file
        descriptor fd, or NULL on error (for example, if fd is not
        connected to a terminal).  The return value may point to static
        data, possibly overwritten by the next call.

   [ttyname manual](https://man7.org/linux/man-pages/man3/ttyname.3.html)

 - ttyslot:
        
        #include <unistd.h>
        int ttyslot(void);

        The legacy function ttyslot() returns the index of the current
        user's entry in some file.

   [ttyslot manual](https://man7.org/linux/man-pages/man3/ttyslot.3.html)

 - ioctl:
        
        #include <sys/ioctl.h>
        int ioctl(int fd, unsigned long request, ...);

        The ioctl() system call manipulates the underlying device
        parameters of special files.  In particular, many operating
        characteristics of character special files (e.g., terminals) may
        be controlled with ioctl() requests.  The argument fd must be an
        open file descriptor.

   [ioctl manual](https://man7.org/linux/man-pages/man2/ioctl.2.html)

 - getenv:

        #include <stdlib.h>
        char *getenv(const char *name);

        The getenv() function searches the environment list to find the
        environment variable name, and returns a pointer to the
        corresponding value string.

   [getenv manual](https://man7.org/linux/man-pages/man3/getenv.3.html)

 - tcsetattr:
        
        #include <termios.h>
        int tcsetattr(int fildes, int optional_actions,
           const struct termios *termios_p);

        The tcsetattr() function shall set the parameters associated with
        the terminal referred to by the open file descriptor fildes (an
        open file descriptor associated with a terminal) from the termios
        structure referenced by termios_p as follows:

   [tcsetattr manual](https://man7.org/linux/man-pages/man3/tcsetattr.3p.html)

 - tcgetattr:

        #include <termios.h>
        int tcgetattr(int fildes, struct termios *termios_p);

        he tcgetattr() function shall get the parameters associated with
        the terminal referred to by fildes and store them in the termios
        structure referenced by termios_p.  The fildes argument is an
        open file descriptor associated with a terminal.

   [tcgetattr manual](https://man7.org/linux/man-pages/man3/tcgetattr.3p.html)


 - tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs:

        #include <curses.h>
        #include <term.h>

        These routines are included as a conversion aid for programs that use the
        termcap library. Their parameters are the same and the routines are 
        emulated using the terminfo database. Thus, they can only be used to 
        query the capabilities of entries for which a terminfo entry has been
        compiled. 

        See manual for details!

   [tgetent manual](https://linux.die.net/man/3/tgetent)

