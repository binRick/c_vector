default: build
##############################################################
clean:
	@rm -rf build
build: clean
	@meson setup build
	@meson compile -C build
	@env MESON_TESTTHREADS=3 meson test -C build --print-errorlogs	
install: build
	@meson install -C build
