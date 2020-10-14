#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}


int 
sys_modeswitch(void)
{
  int n;
  (argint(0, &n));
  set_mode(n);
  set_palette_256();
  return 22;
}

int
sys_plotpixel(void)
{
	int n,j,i,color;
	(argint(0, &n));
	j = n;
	argint(1,&n);
	i = n;
	argint(2,&n);
	color = n;
	plot_pixel(i,j,color);
	return 23;
}

int
sys_plotrectangle(void)
{
  
  int n,i1,i2,i3,i4,color;
	argint(0, &n);
	i1 = n;
	argint(1,&n);
	i2 = n;
	argint(2,&n);
	i3 = n;
	argint(3, &n); 
	i4 = n;
	argint(4,&n);
	color = n;
  
	plot_rectangle(i1,i2,i3,i4,color);
  return 24;
}

