#include "header.h"


int main() {

	Cache* cache = create_cache(MAX_CACHE);
	cache_init(cache);


	int choose = menu();

	while (choose != EXIT) {

		if (choose == FIND_IP) find_IP(cache);
		else if(choose == FIND_DOMAIN) find_domain(cache);
		else if(choose == ADD_TO_FILE) add_to_file();
		else if(choose == OUTPUT) output_cache(cache);

		choose = menu();

	}

	free_memory(cache);

	return 0;

}	