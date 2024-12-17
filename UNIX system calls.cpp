#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644); 
    if (fd < 0) { perror("open"); return 1; }
    write(fd, "Hello, World!\n", 14); 
    close(fd); 
    fd = open("example.txt", O_RDONLY); 
    if (fd < 0) { perror("open"); return 1; }
    char buffer[20];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1); 
    if (bytesRead < 0) { perror("read"); close(fd); return 1; }
    buffer[bytesRead] = '\0'; 
    write(STDOUT_FILENO, buffer, bytesRead); 
    close(fd);
    unlink("example.txt"); 
    return 0;
}
