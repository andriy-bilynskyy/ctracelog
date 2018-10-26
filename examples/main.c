#include "trace_log.h"
#include <stdint.h>


void va_print_test(const char *comment, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    trace_vlog(LOG_DEBUG, comment, fmt, ap);
    va_end(ap);
}

int main(void)
{

    trace_log_setlevel(LOG_INFO);

    trace_log_printf(LOG_INFO, "this is info");
    trace_log_printf(LOG_DEBUG, "this is debug");
    trace_log_printf(LOG_WARNING, "this is warning");
    trace_log_printf(LOG_ERROR, "this is error");
    trace_log_printf(LOG_CRITICAL, "this is critical");

    trace_log_printf(LOG_DEBUG, "print parameters %d, %s, %f", 157, "test",157.0);

    uint8_t buf[] = {1,2,3,4,5,6,7,8,9,0};
    trace_log_printbuf(LOG_WARNING, buf, sizeof(buf), "small buffer of %u elements", sizeof(buf));

    uint8_t bufl[100];
    for(uint8_t i =0; i < 100; i++) bufl[i] = i;
    trace_log_printbufl(LOG_DEBUG, bufl, sizeof(bufl), "big buffer of %u elements", sizeof(bufl));

    trace_log_set_output(stderr);
    trace_log_printf(LOG_CRITICAL, "this is printed to std error. can be used any FILE.");
    trace_log_set_output(stderr);

    trace_log_printf(LOG_INFO, "the next print will be disabled");
    trace_log_setlevel(LOG_OFF);
    trace_log_printf(LOG_CRITICAL, "this is suppressed message");
    trace_log_setlevel(LOG_DEBUG);
    trace_log_printf(LOG_DEBUG, "this is shown message");
    trace_log_printf(LOG_INFO, "this is suppressed message");

    trace_log_assert(sizeof(buf) == sizeof(bufl), LOG_CRITICAL, "this shouldn't happen!");
    trace_log_assert(trace_log_getlevel() == LOG_DEBUG, LOG_CRITICAL, "that's fine just for test (should be not printed).");

    va_print_test("va_print", "{%s}{%d}", "test", 157);

    return 0;
}
