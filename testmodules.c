#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/task.h>
#include <linux/sched/signal.h>

struct task_struct *task_ptr;

MODULE_LICENSE("GPL");

void DFS(struct task_struct *task) {
  struct task_struct *child;
  struct list_head *list;

  printk("name: %s, pid: [%d]\n", task->comm, task->pid);
  list_for_each(list, &task->children) {
    child = list_entry(list, struct task_struct, sibling);
    DFS(child);
  }
}

static int tasklist_init(void) {
  printk(KERN_INFO "Loading Task Lister Module...\n");
  /**DFS(&init_task);*/
	task_ptr = &init_task;
  for_each_process(task_ptr) {
    printk("Name: %s PID: [%d]\n", task_ptr->comm, task_ptr->pid);
  }
  return 0;
}

static void tasklist_exit(void) { printk(KERN_ALERT "Bye my kernel module\n"); }

module_init(tasklist_init);
module_exit(tasklist_exit);
