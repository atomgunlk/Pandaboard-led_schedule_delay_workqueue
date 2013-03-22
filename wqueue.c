#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
//#include "pwm.h"
static void workqueue_handler(void);

static struct workqueue_struct *aworkq = 0;
static DECLARE_DELAYED_WORK(aworkq_work, workqueue_handler);
char exitschd = 0;
static void workqueue_handler(void){
	static unsigned long prvjiffies = 0;
	printk(KERN_ALERT "my workqueue work %lu\n",jiffies - prvjiffies);
	prvjiffies = jiffies;
	if (exitschd == 0)
		queue_delayed_work(aworkq,&aworkq_work,HZ/2);
}
static int __init schd_start(void) {
	if(!aworkq){
		aworkq = create_singlethread_workqueue("aworkq");
	}
	if(aworkq){
		queue_delayed_work(aworkq,&aworkq_work,HZ/2);
	}

	// return success
	return 0;
}

static void __exit schd_end(void) {
	int err = 0;
	exitschd = 1;
	if (aworkq){
		err = cancel_delayed_work(&aworkq_work);
		if(err){
			flush_workqueue(aworkq);
		}
		destroy_workqueue(aworkq);
	}
}

// entry and exit points
module_init(schd_start);
module_exit(schd_end);

// do some kernel module documentation
MODULE_AUTHOR("Likhit Kanthathong <likhit@forth.co.th>");
MODULE_DESCRIPTION("OMAP Schedule_delay and workqueues");
MODULE_LICENSE("GPL");
