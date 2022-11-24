#include <stdio.h>
#include <stdlib.h>
/*
 количество целых чисел из диапазона от 1 до N, в двоичном представлении которых содержится ровно K значащих нулей.
Input N K
 */
unsigned int cnk(int k, int n) {
    const unsigned int maxn = 33;
    unsigned int C[maxn+1][maxn+1] = {0};
    for (int nn=0; nn<=n; ++nn) {
        C[nn][0] = C[nn][nn] = 1;
        for (int kk=1; kk<nn; ++kk) {
            C[nn][kk] = C[nn-1][kk-1] + C[nn-1][kk];
            // printf("%d ", C[nn][kk]);
        }
    }
    return C[n][k];
}
unsigned int cnk2(int k, int n) {
    const unsigned int maxn = 33;
    unsigned int c1[maxn+1] = {1};
    unsigned int c2[maxn+1] = {1,1};
    unsigned int *cur = c1, *pred = c2;
    for (int nn=0; nn<=n; ++nn) {
        cur[0] = cur[nn] = 1;
        //for(size_t s=0; s<n-nn; s++)
        //    printf("  ");
        //printf("1 ");
        for (int kk=1; kk<nn; ++kk) {
            cur[kk] = pred[kk-1] + pred[kk];
        //    printf("%4d", cur[kk]);
        }
        unsigned int *tmp = cur;
        cur = pred;
        pred = tmp;
        //(nn)? printf("  1\n") : printf("\n");
    }
    return cur[k];
}

int bb(int n) {
	int biggest_bit = 0;
    unsigned int mask = 0x1;
	while (n >= mask) {
        mask <<= 1;
		biggest_bit++;
	}
	return biggest_bit;
}

unsigned int resh3(unsigned int a, int k, int size) {
    unsigned int ans = 0;
    //printf("resh3:\n");
    while( size>=0 ) {
        //printf("a = %u size = %d k = %d\n",((a>>(size-1))&1), size, k);
        if( k>size || k<0 )
            return ans;
        if( k==size )
            return ans+1;
        if( (a>>(size-1)&1) == 1 )
            ans += cnk(k - 1, size - 1);
        else
            k--;
        size--;
    }
    return ans;
}

int main(void) {
	unsigned int ans = 0;
	unsigned int n, k, save_n;

	scanf("%u%u", &n, &k);

    //printf("soch = %u\n",soch(k,n));
    //printf("soch2 = %u\n",soch2(k,n));
    //printf("soch3 = %u\n",soch3(k,n));

    save_n = n;
    
    unsigned int biggest_bit = bb(n);
    unsigned int n_as_arr[32] = {0};
	for (int i = k; i < biggest_bit - 1; i++) {
		ans += cnk(k, i);
	}
    // printf("\n%u\n", (resh3(save_n, k, biggest_bit - 1) + ans ));
    biggest_bit--;
    // printf("biggest bit = %u\n", biggest_bit);
    while( biggest_bit >= 0 ) {
        // printf("%u size = %d k = %d ans = %d\n",((save_n>>(biggest_bit-1))&1), biggest_bit, k, ans);
        if( k>biggest_bit || k<0 )
            break;
        if( k==biggest_bit ) {
            ans++;
            break;
        }
        biggest_bit--;
        if( (save_n>>(biggest_bit)&1) == 1 ) {
            //printf("===%d ",biggest_bit);
            ans += cnk(k - 1, biggest_bit);
        }
        else
            k--;
    }
    printf("%u\n",  ans );
	return 0;

}
