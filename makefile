build: pwdgen

install: pwdgen
	sudo cp $< /usr/local/bin 

clean:
	rm pwdgen

.PHONY: build install clean

################################

pwdgen: pwdgen.c
	cc -Wall -Wno-unused-result -O3 $< -o $@

