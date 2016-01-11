override CPPFLAGS += -Iinclude
CFLAGS += -std=c99

PROGS = analyze-x86
SRCS = $(PROGS:%=%.c)
DEPS = $(SRCS:%.c=%.d)

DEPEND.c = $(COMPILE.c) -MM -MP
%.d: %.c
	$(DEPEND.c) $< $(OUTPUT_OPTION)

all: $(PROGS)

clean:
	rm -f $(PROGS) *.o *.d

.PHONY: all clean

-include $(DEPS)
