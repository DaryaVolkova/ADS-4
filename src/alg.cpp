// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int left = 0;
    int right = size;
    int mid;
    int tmp_left, tmp_right;
    int res;
    while (left < right) {
        mid = (left + right) / 2;
        if (value > arr[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    tmp_left = left;
    left = 0;
    right = size;
    while (left < right) {
        mid = (left + right) / 2;
        if (value < arr[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    tmp_right = right;
    res = tmp_right - tmp_left;
    return res;
}

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value) count++;
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int* begin = arr, * end = &arr[len - 1];
    while (*end > value) {
        end--;
    }
    end++;
    int* tmp = end;
    do{
        if ((begin != end) && ((*begin + *end) == value)) {
            count++;
            end--;
        } else if ((*begin + *end) < value) {
            begin++;
            end = tmp;
        } else {
            end--;
        }
    } while (begin != tmp);
    return count / 2;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    int search_val = 0;
    for (int i = 0; i < len; i++) {
        search_val = value - arr[i];
        count += cbinsearch(arr, len, search_val);
        if (search_val == value / 2) count--;
    }
    return count / 2;
}
