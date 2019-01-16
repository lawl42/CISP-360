// Caesar Cipher

#include <stdio.h>
#include <string.h>

int main()
{
	char input[] = "jzfnlyetxlrtypdzxlyjxzyvpjdtyespoltwjxltwlwwzqespxnzxtyrlyzyjxzfdwjdzespjwplgpyzecltwtypgpceszfrsetoslgplyloxtcpcqczxzgpcdpldmfedzxpzyptddpyotyrxpdeletzylcjqtwwpohtesnstxalykppddzxpnstxadtydhtxdfteddzxpnstxadlcpdhtyrtyrqczxlgtypdzxpnstxadtyulnvmzzeddzxpnstxadeslehtdsespjnzfwompxtypdelcdvjlyosfensnstxadlnstxahszddteetyrzyespnlylaltczqofensnstxadhszdpyoesptcwzgpqczxlxdepcolxlyzespcazdenlcohtesnstxalykppdlyopgpcjzyptdloocpddpoezxp";
	for (int i = 1; i <= 26; i++) {
		printf("%d ", i);
		for (int j = 0; j < strlen(input); j++) {
			if (++input[j] > 'z') {
				input[j] -= 26;
			}
			printf("%c", input[j]);
		}
		printf("\n");
	}
}