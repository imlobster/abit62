#pragma once
#include <cstdint>
namespace abit62 {
	inline constexpr char alphabet[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	inline uint64_t pcg=42;
	inline bool init(const void* const ptr) { // pointer adress is pretty random
		if(!ptr)return false;
		pcg=reinterpret_cast<uintptr_t>(ptr); // assign pointer adress as value
		return true;
	}
	inline bool string(char* const ic,const uint8_t len) { // ic - input char; len - number of characters to be filled
		if(!ic)return false;
		for(uint8_t i=0;i<len;++i) {
			pcg=pcg*6364136223846793005ULL+1442695040888963407ULL; // PCG const's
			uint8_t tc=(pcg>>32)%62;
			ic[i]=alphabet[tc]; // swapping 62 range with characters
		}
		return true;
	}
}
