#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <git2.h>

int main(int argc, char *argv[])
{
	const char *local_repo = "/home/vincent/CODE/gittools/test";
	const char *remote_url = "ssh://github.com:plinaky/fsm.git";

	/* Initialiser la bibliothèque libgit2 */
	git_libgit2_init();

	/* Créer un dépôt */
	git_repository *repo = NULL;
	git_repository_init(&repo, local_repo, 0);

	/* Effectuer des opérations Git, par exemple, cloner un dépôt */
	git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
	git_clone(&repo, remote_url, local_repo, &clone_opts);

	/* Libérer les ressources */
	git_repository_free(repo);
	git_libgit2_shutdown();

	return 0;
}
