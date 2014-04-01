﻿#pragma once
// Copyright (c) 2014, Alexandre Mutel
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following 
// conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following 
//    disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
//    disclaimer in the documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF 
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
// OF THE POSSIBILITY OF SUCH DAMAGE.

#include "Common.h"
#include <algorithm>

namespace gcix
{

	class Memory
	{
	public:
		static inline void Free(void* ptr)
		{
			return free(ptr);
		}

		static inline void* Allocate(size_t size)
		{
			return malloc(size);
		}

		static inline void* AllocateZero(size_t size)
		{
			void* ptr = malloc(size);
			if (ptr == nullptr)
			{
				return ptr;
			}
			memset(ptr, 0, size);
			return ptr;
		}

		static inline void* ReAllocate(void* ptr, size_t size)
		{
			return realloc(ptr, size);
		}

		/**
		Clear/zero a small region of memory
		*/
		static inline void ClearSmall(void* from, int size)
		{
			gcix_assert((size & 3) == 0);

			// This is usually translated to a rep stosd in x86
			for(int i = 0; i < size/4; i++)
			{
				((uint32_t*)from)[i] = 0;
			}
		}

		static inline void FastClearMemory128BytesOnAligned16bytes(void* ptr)
		{
			// TODO
		}
	};
}