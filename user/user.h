struct stat;
#ifdef LAB_SYSCALL
struct sysinfo;
#endif
#ifdef LAB_MMAP
typedef unsigned long size_t;
typedef long int off_t;
#endif
struct stat;

// system calls
int fork(void);
int exit(int) __attribute__((noreturn));
int wait(int*);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(const char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
#ifdef LAB_SYSCALL
int trace(int);
int sysinfo(struct sysinfo *);
#endif
#ifdef LAB_PGTBL
int pgaccess(void *base, int len, void *mask);
int ugetpid(void);
#endif
#ifdef LAB_TRAPS
int sigalarm(int ticks, void (*handler)());
int sigreturn(void);
#endif
#ifdef LAB_NET
int connect(uint32, uint16, uint16);
#endif
#ifdef LAB_FS
int symlink(char* target, char* path);
#endif
#ifdef LAB_MMAP
void *mmap(void *addr, size_t length, int prot, int flags,
           int fd, off_t offset);
int munmap(void *addr, size_t length);
#endif

// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void fprintf(int, const char*, ...);
void printf(const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
int memcmp(const void *, const void *, uint);
void *memcpy(void *, const void *, uint);
#ifdef LAB_LOCK
int statistics(void*, int);
#endif
