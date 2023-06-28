// rssh.h
#ifndef RSSH_H
#define RSSH_H

#define MAX_HOSTS 10

struct Host {
    char name[50];
    char host_ip[50];
    char password[50];
};

int read_config_file(char* filename, struct Host* hosts);
int choose_host(struct Host* hosts, int num_hosts);
int connect_to_host(struct Host* host);

#endif /* RSSH_H */


// rssh.c
#include <stdio.h>
#include <stdlib.h>

int read_config_file(char* filename, struct Host* hosts) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening config file");
        return 0;
    }
    int i = 0;
    while (i < MAX_HOSTS && fscanf(file, "%s %s %s", 
            hosts[i].name, hosts[i].host_ip, hosts[i].password) == 3) {
        i++;
    }
    fclose(file);
    return i;
}

int choose_host(struct Host* hosts, int num_hosts) {
    printf("Registered hosts:\n");
    for (int i = 0; i < num_hosts; i++) {
        printf("%d. %s (%s)\n", i+1, hosts[i].name, hosts[i].host_ip);
    }
    printf("Choose a host (1-%d): ", num_hosts);
    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > num_hosts) {
        printf("Invalid choice\n");
        return -1;
    }
    return choice - 1;
}

int connect_to_host(struct Host* host) {
    char command[200];
    sprintf(command, "sshpass -p '%s' ssh root@%s", host->password, host->host_ip);
    return system(command);
}

int scan_host_key(struct Host* host) {
    char command[200];
    sprintf(command, "ssh-keyscan %s >> ~/.ssh/known_hosts", host->host_ip);
    return system(command);
}

int main() {
    
    struct Host hosts[MAX_HOSTS];
    int num_hosts = read_config_file("/etc/rssh/config.txt", hosts);
    if (num_hosts == 0) {
        return 1;
    }
    int choice = choose_host(hosts, num_hosts);
    if (choice < 0) {
        return 1;
    }

    scan_host_key(&hosts[choice]);
    connect_to_host(&hosts[choice]);
    return 0;
}

