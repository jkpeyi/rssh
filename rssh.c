#include <stdio.h>
#include <stdlib.h>
#include "rssh.h"

int read_config_file(char *filename, struct Host *hosts)
{
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        perror("Error opening config file");
        return 0;
    }

    int i = 0;

    while (i < MAX_HOSTS && fscanf(file, "%s %s %s", hosts[i].name, hosts[i].host_ip, hosts[i].password) == 3)
    {
        i++;
    }
    
    fclose(file);
    return i;
}

int choose_host(struct Host *hosts, int num_hosts)
{
    printf("Registered hosts:\n");
    for (int i = 0; i < num_hosts; i++)
    {
        printf("%d. %s (%s)\n", i + 1, hosts[i].name, hosts[i].host_ip);
    }
    printf("Choose a host (1-%d): ", num_hosts);
    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > num_hosts)
    {
        printf("Invalid choice\n");
        return -1;
    }
    return choice - 1;
}

int connect_to_host(struct Host *host)
{
    char command[200];
    sprintf(command, "sshpass -p '%s' ssh root@%s", host->password, host->host_ip);
    return system(command);
}

int scan_host_key(struct Host *host)
{
    char command[200];
    sprintf(command, "ssh-keyscan %s >> ~/.ssh/known_hosts", host->host_ip);
    return system(command);
}
