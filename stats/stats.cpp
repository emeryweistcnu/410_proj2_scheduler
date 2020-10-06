/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector) {
	av_turnaround_time = 0.0;
	av_response_time = 0.0;
	av_wait_time = 0.0;
	vec = &finished_vector;
}

void Stats::showAllProcessInfo() {
	if (vec->size() < 1) return;

	for (int i = 0; i < vec->size(); i++){
		std::cout << "Process " << i << " Required CPU time: " << vec->at(i).required_cpu_time << " arrived: " << vec->at(i).arrival_time << " started: "
				<< vec->at(i).start_time << " finished: " << vec->at(i).finish_time << std::endl;
	}
}

float Stats::get_av_response_time() {
	float r = 0.0;
	for (int i = 0; i < vec->size(); i++){
		r += (vec->at(i).start_time - vec->at(i).arrival_time);
	}
	return r / vec->size();
}

float Stats::get_av_turnaround_time() {
	float t = 0.0;
	for (int i = 0; i < vec->size(); i++){
		t += (vec->at(i).finish_time - vec->at(i).arrival_time);
	}
	return t / vec->size();
}

float Stats::get_av_wait_time() {
	float w = 0.0;
	for (int i = 0; i < vec->size(); i++){
		w += (vec->at(i).finish_time - vec->at(i).arrival_time - vec->at(i).required_cpu_time);
	}
	return w / vec->size();
}

void Stats::calcStats() {
	av_turnaround_time = get_av_turnaround_time();
	av_response_time = get_av_response_time();
	av_wait_time = get_av_wait_time();
}
