int number_is_simple(long int number) {
    for (long int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return 0;
        }
    }
    if (number < 2) {
        return 0;
    }
    return 1;
}
