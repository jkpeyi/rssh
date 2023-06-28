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
