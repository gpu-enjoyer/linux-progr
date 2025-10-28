#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iostream>

void check(
    bool ok,
    const char* msg)
{
    if (!ok)
    {
        std::cerr << msg << ": " << strerror(errno) << "\n";
        std::exit(1);
    }
}

class File
{
    FILE* f;

public:

    File(
        const char* name,
        const char* mode)
    {
        f = fopen(name, mode);
        check(f != nullptr, "fopen");
    }

    File(const File&) = delete;             // copy prohibition
    File& operator=(const File&) = delete; 

    File(File&& other) : f(other.f)
    {
        other.f = nullptr;
    }

    File& operator=(File&& other)
    {
        if (this != &other)
        {
            if (f) fclose(f);   // close old f
            f = other.f;        // get pointer
            other.f = nullptr;  // null source
        }
        return *this;
    }

    ~File()
    {
        if (f) check(fclose(f) == 0, "fclose");
    }

    void write(
        const void* buf,
        size_t size,
        size_t count)
    {
        size_t n = fwrite(buf, size, count, f);
        check(n == count, "fwrite");
    }

    void read(
        void* buf,
        size_t size,
        size_t count)
    {
        size_t n = fread(buf, size, count, f);
        check(n == count, "fread");
    }

    void rewind_file()
    {
        rewind(f);  // go to the file' begin
    }
};

int main()
{
    File f1("test.txt", "w+");  // write + read

    const char msg[] = "hello\n";

    f1.write(msg, 1, sizeof(msg)-1);
    f1.rewind_file();

    File f2 = std::move(f1);

    char buf[16] = {};
    f2.read(buf, 1, sizeof(msg)-1);
    std::cout << buf;

    return 0;
}
