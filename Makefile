default: all
##############################################################
build: 
	@if [[ -d build ]]; then /usr/local/bin/meson setup --fatal-meson-warnings --buildtype debug --default-library shared --warnlevel 1 --backend ninja --errorlogs --reconfigure build; else /usr/local/bin/meson setup --fatal-meson-warnings --buildtype debug --default-library shared --warnlevel 1 --backend ninja --errorlogs build; fi
	@/usr/local/bin/passh -L build/build.log /usr/local/bin/meson compile -C build -j 15
	@env MESON_TESTTHREADS=3 /usr/local/bin/passh /usr/local/bin/meson test -C build --print-errorlogs	

