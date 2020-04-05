/*
MIT License

Copyright (c) 2019 Michael Kösel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once

#include <device_launch_parameters.h>
#include <curand_kernel.h>

namespace dogm
{

struct GridCell;
struct MeasurementCell;
struct Particle;

__global__ void setupRandomStatesKernel(curandState* __restrict__ states, unsigned long long seed, int count);

__global__ void initParticlesKernel(Particle* __restrict__ particle_array, curandState* __restrict__ global_state, 
	float velocity, int grid_size, int particle_count);

__global__ void initBirthParticlesKernel(Particle* __restrict__ birth_particle_array, curandState* __restrict__ global_state, 
	float velocity, int grid_size,
	int particle_count);

__global__ void initGridCellsKernel(GridCell* __restrict__ grid_cell_array, MeasurementCell* __restrict__ meas_cell_array, 
	int grid_size, int cell_count);

__global__ void reinitGridParticleIndices(GridCell* __restrict__ grid_cell_array, int cell_count);

} /* namespace dogm */