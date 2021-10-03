#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char all_chars[] =
	"(2<FPZdnx)3=GQ[eoy*4>HR\\fpz!+5?IS]gq{\",6@JT^hr|#-7AKU_is}$"
	".8BLV`jt~%/9CMWaku&0:DNXblv'1;EOYcmw";

char num_chars[] = "0123456789";

char alpha_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

char alphanum_chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main(int argc, char **argv) {

	char *chars = all_chars;
	int chars_size = sizeof(all_chars);

	int char_count = 32;
	if (argc > 1) {
		char_count = atoi(argv[1]);
	}
	if (argc > 2) {
		if (!strcmp(argv[2], "-all")) {
			chars = all_chars;
			chars_size = sizeof(all_chars);
		} else if (!strcmp(argv[2], "-num")) {
			chars = num_chars;
			chars_size = sizeof(num_chars);
		} else if (!strcmp(argv[2], "-alpha")) {
			chars = alpha_chars;
			chars_size = sizeof(alpha_chars);
		} else if (!strcmp(argv[2], "-alphanum")) {
			chars = alphanum_chars;
			chars_size = sizeof(alphanum_chars);
		}
	}

	FILE *urandom = fopen("/dev/urandom", "r");

	unsigned char buffer[char_count];

	fread(buffer, 1, char_count, urandom);

	for (int i = 0; i < char_count; i++) {
		putchar(chars[buffer[i] % chars_size]);
	}
	putchar('\n');

	fclose(urandom);

	return 0;
}

