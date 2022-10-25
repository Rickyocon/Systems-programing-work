#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd;
    unsigned char b;
    int count;
    ssize_t ret;

    fd = open("/etc/passwd", O_RDONLY);
    if (fd < 0) {
        write(2, "Error opening /etc/password\n", 28);
        return 1;
    }

    count = 0;
    for (;;) {
        ret = read(fd, &b, 1);
        if (ret == 0) { // end of file
            break;
        }
        if (ret < 0) { // error
            if (errno == EINTR)
                continue;
            write(2, "Read error on /etc/password\n", 28);
            return 1;
        }
        if (b == '\n') {
            // reset count, print b
            count = 0;
        } else
        if (b == ':') {
            // increment count, print ':' only if count == 1
            count = count + 1;
            if (count != 1)
                continue;
        } else
        if (count != 0 && count != 6) {
            // print b only if count is 0 or 6
            continue;
        }
        for (;;) {
            ret = write(1, &b, 1);
            if (ret == 1)
                break;
            if (ret < 0 && errno == EINTR)
                continue;
            write(2, "Write error\n", 12);
            return 1;
        }
    }