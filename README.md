# rssh

"rssh" is a command line tool that allows you to easily connect to multiple remote hosts by reading a configuration file that includes the IP addresses, host names, and passwords for each remote host. "rssh" then uses the `sshpass` package to automatically establish an SSH connection with the selected remote host.

## Installation

### Prerequisites
- A Unix-based operating system (such as Linux, macOS, or BSD)
- The `sshpass` package installed on your system
- Basic knowledge of the command line

### Installation Steps
1. Download the "rssh" binary and configuration file from the project's GitHub repository to your local machine.
2.  Decompress the "rssh.tar.gz" file into a "rssh" directory

3. Move the "rssh" directory to `/usr/local/share/` by running the following command: 

sudo mv rssh /usr/local/share/

4. Add the "rssh" command to your system's PATH by editing the `.bashrc` or `.zshrc` file in your home directory:

echo "export PATH=$PATH:/usr/local/share/rssh" >> ~/.bashrc

Or

echo "export PATH=$PATH:/usr/local/share/rssh" >> ~/.zshrc

5. Reload your shell configuration by running the following command:

source ~/.bashrc
source ~/.zshrc

If it doesn't work try aliasing the command:

alias rssh="/usr/local/share/rssh/rssh"

(In your .bashrc or .zshrc file) cf. step 4,5


