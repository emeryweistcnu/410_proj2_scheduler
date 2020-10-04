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
		std::cout << "Process " << i << " Required CPU time: " << vec->at(i).required_cpu_time << "arrived: " << vec->at(i).arrival_time << "started: "
				<< vec->at(i).start_time << "finished: " << vec->at(i).finish_time << std::endl;
	}
}

float Stats::get_av_response_time() {
	return av_response_time;
}

float Stats::get_av_turnaround_time() {
	return av_turnaround_time;
}

float Stats::get_av_wait_time() {
	return av_wait_time;
}

void Stats::calcStats() {
	for (int i = 0; i < vec->size(); i++){
			av_response_time += (vec->at(i).start_time - vec->at(i).arrival_time);
			av_turnaround_time += (vec->at(i).finish_time - vec->at(i).arrival_time);
			av_wait_time += (vec->at(i).finish_time - vec->at(i).arrival_time - vec->at(i).required_cpu_time);
		}

	av_response_time /= vec->size();
	av_turnaround_time /= vec->size();
	av_wait_time /= vec->size();
}
