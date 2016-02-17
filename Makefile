
MINGW_PFX = i686-w64-mingw32
INSTALL_PATH?=/usr/local

.DUMMY: all

all: oculus_shm_adapter.exe no_xselectinput.so

oculus_shm_adapter.exe: oculus_shm_adapter.c
	$(MINGW_PFX)-gcc $< -o $@ -Os -shared-libgcc
	$(MINGW_PFX)-strip --strip-unneeded $@

no_xselectinput.so: no_xselectinput.c
	gcc $< -o $@ -shared -fPIC -Os
	strip --strip-unneeded $@
	
install:
	cp oculus_wine_wrapper.sh $(INSTALL_PATH)/bin/oculus-wine-wrapper.sh
	ln -s $(INSTALL_PATH)/bin/oculus-wine-wrapper.sh $(INSTALL_PATH)/bin/oculus-wine-wrapper
	mkdir $(INSTALL_PATH)/lib/oculus-wine-wrapper/
	cp no_xselectinput.so $(INSTALL_PATH)/lib/oculus-wine-wrapper/no_xselectinput.so
	cp oculus_shm_adapter.exe $(INSTALL_PATH)/lib/oculus-wine-wrapper/oculus_shm_adapter.exe
	
uninstall:
	rm -f $(INSTALL_PATH)/bin/oculus-wine-wrapper.sh
	rm -rf $(INSTALL_PATH)/lib/oculus-wine-wrapper
