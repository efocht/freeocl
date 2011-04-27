/*
	FreeOCL - a free OpenCL implementation for CPU
	Copyright (C) 2011  Roland Brochard

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "sampler.h"
#include "context.h"

#define SET_RET(X)	if (errcode_ret)	*errcode_ret = (X)

extern "C"
{
	cl_sampler clCreateSampler (cl_context context,
								cl_bool normalized_coords,
								cl_addressing_mode addressing_mode,
								cl_filter_mode filter_mode,
								cl_int *errcode_ret)
	{
		return context->dispatch->clCreateSampler(context,
												  normalized_coords,
												  addressing_mode,
												  filter_mode,
												  errcode_ret);
	}

	cl_sampler clCreateSamplerFCL (cl_context context,
								cl_bool normalized_coords,
								cl_addressing_mode addressing_mode,
								cl_filter_mode filter_mode,
								cl_int *errcode_ret)
	{
		SET_RET(CL_INVALID_OPERATION);
		return NULL;
	}

	cl_int clRetainSampler (cl_sampler sampler)
	{
		return sampler->dispatch->clRetainSampler(sampler);
	}

	cl_int clRetainSamplerFCL (cl_sampler sampler)
	{
		return CL_INVALID_SAMPLER;
	}

	cl_int clReleaseSampler (cl_sampler sampler)
	{
		return sampler->dispatch->clReleaseSampler(sampler);
	}

	cl_int clReleaseSamplerFCL (cl_sampler sampler)
	{
		return CL_INVALID_SAMPLER;
	}

	cl_int clGetSamplerInfo (cl_sampler sampler,
							 cl_sampler_info param_name,
							 size_t param_value_size,
							 void *param_value,
							 size_t *param_value_size_ret)
	{
		return sampler->dispatch->clGetSamplerInfo(sampler,
												   param_name,
												   param_value_size,
												   param_value,
												   param_value_size_ret);
	}

	cl_int clGetSamplerInfoFCL (cl_sampler sampler,
							 cl_sampler_info param_name,
							 size_t param_value_size,
							 void *param_value,
							 size_t *param_value_size_ret)
	{
		return CL_INVALID_SAMPLER;
	}
}