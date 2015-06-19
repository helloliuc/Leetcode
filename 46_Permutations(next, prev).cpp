//next/prev_permutation可以处理有重复元素问题
template<typename BidirectionalIterator>
bool my_next_permutation(BidirectionalIterator first, BidirectionalIterator last) {
    if(last - first <= 1) return false;

    for(BidirectionalIterator i = last - 1; i > first; i--) {
        if(*(i - 1) < *i) {
            for(BidirectionalIterator j = last - 1; j >= i; j--) {
                if(*(i - 1) < *j) {
                    swap(*(i - 1), *j);
                    reverse(i, last);
                    return true;
                }
            }
        }
    }
    reverse(first, last);
    return false;
}

template<typename BidirectionalIterator>
bool my_prev_permutation(BidirectionalIterator first, BidirectionalIterator last) {
    if(last - first <= 1) return false;

    for(BidirectionalIterator i = last - 1; i > first; i--) {
        if(*(i - 1) > *i) {
            for(BidirectionalIterator j = last - 1; j >= i; j--) {
                if(*(i - 1) > *j) {
                    iter_swap(i - 1, j);
                    reverse(i, last);
                    return true;
                }
            }
        }
    }
    reverse(first, last);
    return false;
}

void permutation(int pos, int *a, int n) {
    if(pos >= n) {
        for(int i=0; i<n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return ;
    }
    for(int i=pos; i<n; i++) {
      //若有重复元素，这里需判断，如果之前与这个数交换过，则不再交换
        swap(a[pos], a[i]);
        permutation(pos+1, a, n);
        swap(a[pos], a[i]);
    }
}
