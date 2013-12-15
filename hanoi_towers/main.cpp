#include <Stack.h>


typedef int Disk;

class Tower
{
public:
    Stack<Disk> disks;

    void add(const Disk &disk)
    {
        if (!disks.empty() && disk > disks.peek())
            throw "Can't add a bigger disk";
        disks.push(disk);
    }

    void moveTopTo(Tower &destination)
    {
        destination.add(disks.peek());
        disks.pop();
    }

    void moveDisksTo(int nr_of_disks, Tower &buffer, Tower &destination)
    {
        if (nr_of_disks <= 0)
            return;

        moveDisksTo(nr_of_disks - 1, destination, buffer);
        moveTopTo(destination);
        buffer.moveDisksTo(nr_of_disks - 1, *this, destination);
    }
};


int main()
{
    Tower a, b, c;

    a.add(Disk(3));
    a.add(Disk(2));
    a.add(Disk(1));

    a.moveDisksTo(3, b, c);

    return 0;
}
