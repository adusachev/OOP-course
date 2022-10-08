//void print_array(int n, int array[]) {
//
//    for (int i = 0; i < n; i++) {
//        std::cout << array[i] << " ";
//    }
//    std::cout << std::endl;
//}


//void reverse() {
//    const int n = 8;
//    int a[n] = { 0, 1, 2, 3, 4, 5, 6, 7 };
//
//    const int m = 7;
//    int b[m];
//    for (int i = 0; i < m; i++) {
//        b[i] = a[i];
//    }
//
//
//    for (int i = 0; i < n - m; i++) {
//        a[i] = a[i + m];
//    }
//
//    int j = 0;
//    for (int i = n - m; i < n; i++) {
//        a[i] = b[j];
//        j++;
//    }
//
//    print_array(n, a);
//}