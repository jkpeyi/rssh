#include <stdio.h>
#include "rssh.h"

int main()
{

    struct Host hosts[MAX_HOSTS];

    int num_hosts = read_config_file("/etc/rssh/config.txt", hosts);

    if (num_hosts == 0)
    {
        return 1;
    }

    int choice = choose_host(hosts, num_hosts);

    if (choice < 0)
    {
        return 1;
    }

    scan_host_key(&hosts[choice]);
    connect_to_host(&hosts[choice]);

    return 0;
}
