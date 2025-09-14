#pragma once
#include <cstdint>
namespace abit62 {
	inline uint64_t pcg=1;
	inline bool init(const void* const ptr) { // pointer adress is pretty random
		if(!ptr)return false;
		pcg=reinterpret_cast<uintptr_t>(ptr);
		return true;
	}
	inline bool string(char* const ic,uint8_t icend) { // maximum length is 256 chars
		if(!ic)return false;
		for(uint8_t i=0;i<icend;++i) {
			pcg=pcg*6364136223846793005ULL+1442695040888963407ULL; // PCG const's
			uint8_t tc=(pcg>>32)%62;
			ic[i]=tc<10?tc+48:(tc<36?tc+87:tc+29); // swapping 62 range with ascii codes
		}
		return true;
	}
}
