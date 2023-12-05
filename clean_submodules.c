#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <git2.h>

static const char *repo_path = "/home/vincent/CODE/gittools/test";
static const char *remote_url = "git@github.com:plinaky/gittools.git";

static void print_error(const char *action, int error_code)
{
	const git_error *err = git_error_last();
	if (err) {
		fprintf(stderr, "%s failed with error: %d - %s\n", action, error_code, err->message);
	} else {
		fprintf(stderr, "%s failed with error: %d\n", action, error_code);
	}
}


static git_repository *repo_open()
{
	/* Créer un dépôt */
	git_repository *repo = NULL;
	if (git_repository_open(&repo, repo_path) < 0)
		print_error("Opening repository", -1);
	else
		printf("Open successful\n");

	return repo;
}

static git_repository *repo_init()
{
	/* Créer un dépôt */
	git_repository *repo = NULL;
	if (git_repository_init(&repo, repo_path, 0) < 0) {
		print_error("Opening repository", -1);
		return -1;
	}
	printf("Init successful\n");
	return 0;
}

static int repo_start()
{
	if (repo_open() < 0) || (repo_init() < 0) {
		git_libgit2_shutdown();
		return -1;
	} 
	
}

static int remote_add()
{
    // Open the repository
    git_repository *repo = NULL;
    if (git_repository_open(&repo, repo_path) < 0) {
        print_error("Opening repository", -1);
        git_libgit2_shutdown();
        return EXIT_FAILURE;
    }

    // Create remote
    git_remote *remote = NULL;
    if (git_remote_create(&remote, repo, remote_name, remote_url) < 0) {
        print_error("Creating remote", -1);
        git_repository_free(repo);
        git_libgit2_shutdown();
        return EXIT_FAILURE;
    }

    printf("Remote '%s' added with URL '%s'\n", remote_name, remote_url);

    // Clean up
    git_remote_free(remote);	
}


int main(int argc, char *argv[])
{
	/* Initialiser la bibliothèque libgit2 */
	if (git_libgit2_init() < 0) {
		fprintf(stderr, "libgit2 initialization failed\n");
		return EXIT_FAILURE;
	}

	if (repo_start() < 0) {
		return EXIT_FAILURE;
	}

	/* Effectuer des opérations Git, par exemple, cloner un dépôt */
	// git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
	// res = git_clone(&repo, remote_url, repo_path, &clone_opts);

	} else {
		printf("Init successful\n");
	}

	/* Libérer les ressources */
	git_repository_free(repo);
	git_libgit2_shutdown();

	return 0;
}
