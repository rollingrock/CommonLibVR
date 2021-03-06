#pragma once


namespace RE
{
	template <class T>
	class GFixedSizeHash
	{
	public:
		// http::/www.cs.yorku.ca/~oz/hash.html
		static inline UPInt SDBM_Hash(const void* a_dataIn, UPInt a_size, UPInt a_seed = 5381)
		{
			const UInt8* data = static_cast<const UInt8*>(a_dataIn);
			UPInt		 hash = a_seed;
			while (a_size > 0) {
				hash = (hash << 16) + (hash << 6) - hash + static_cast<const UPInt>(data[a_size--]);
			}
			return hash;
		}


		UPInt operator()(const T& a_data) const
		{
			return SDBM_Hash(&a_data, sizeof(T));
		}
	};
	STATIC_ASSERT(sizeof(GFixedSizeHash<void*>) == 0x1);
}
