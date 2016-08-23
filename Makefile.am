#
# flinting: FLINT in GAP
#
# This file is part of the build system of a GAP kernel extension.
# Requires automake.
#
ACLOCAL_AMFLAGS = -I m4

BINARCHDIR = bin/$(GAPARCH)
GAPINSTALLLIB = $(BINARCHDIR)/flinting.so

lib_LTLIBRARIES = flinting.la

flinting_la_SOURCES = src/flinting.c
flinting_la_CPPFLAGS = $(GAP_CPPFLAGS) -DCONFIG_H
flinting_la_LDFLAGS = -module -avoid-version
if SYS_IS_CYGWIN
flinting_la_LDFLAGS += -no-undefined -version-info 0:0:0 
flinting_la_LDFLAGS += -Wl,$(GAPROOT)/bin/$(GAPARCH)/gap.dll
endif

all-local: $(GAPINSTALLLIB)

$(GAPINSTALLLIB): flinting.la
	$(mkdir_p) $(BINARCHDIR)
if SYS_IS_CYGWIN
	cp .libs/flinting.dll $(GAPINSTALLLIB)
else
	cp .libs/flinting.so $(GAPINSTALLLIB)
endif

clean-local:
	rm -f $(GAPINSTALLLIB)

distclean-local:
	rm -rf bin/*

doc:
	($(GAPROOT)/bin/gap.sh -A makedoc.g)
