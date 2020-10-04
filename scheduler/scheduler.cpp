/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/scheduler.h"

void Scheduler::add(PCB p) {
	ready_q->push(p);
}

PCB Scheduler::getNext() {
	if(!isEmpty()){
		PCB p = ready_q->front();
		ready_q->pop();
		return p;
	}

	return PCB();
}

bool Scheduler::isEmpty() {
	return ready_q->size() < 1;
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	return (p.remaining_cpu_time < 1 || (preemptive && tick_count - p.start_time >= time_slice));
}

