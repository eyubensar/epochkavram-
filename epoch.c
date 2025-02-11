#include <stdio.h>
#include <time.h>


struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};


union TimeData {
    struct DateTime dt;
    time_t epoch_time;
};

// Tarihi struct'tan time_t'ye (epoch zamanına) çeviren fonksiyon
time_t convertToEpoch(struct DateTime dt) {
    struct tm time_info = {0};
    time_info.tm_year = dt.year - 1900;  // Yıl 1900'dan itibaren sayılır
    time_info.tm_mon = dt.month - 1;     // Ay 0-11 aralığında tutulur
    time_info.tm_mday = dt.day;
    time_info.tm_hour = dt.hour;
    time_info.tm_min = dt.minute;
    time_info.tm_sec = dt.second;
    return mktime(&time_info);
}

int main() {
    union TimeData time1, time2;
    
    // Kullanıcıdan ilk tarih ve saat bilgisini al
    printf("Birinci tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &time1.dt.year, &time1.dt.month, &time1.dt.day, 
          &time1.dt.hour, &time1.dt.minute, &time1.dt.second);
    
    // Kullanıcıdan ikinci tarih ve saat bilgisini al
    printf("\nİkinci tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &time2.dt.year, &time2.dt.month, &time2.dt.day, 
          &time2.dt.hour, &time2.dt.minute, &time2.dt.second);
    
    // Epoch zamanına çevirme
    time1.epoch_time = convertToEpoch(time1.dt);
    time2.epoch_time = convertToEpoch(time2.dt);
    
    // Epoch zaman farkını hesaplama
    double diff_seconds = difftime(time2.epoch_time, time1.epoch_time);
    
    // Sonuçları ekrana yazdırma
    printf("\nBirinci zamanin Epoch değeri: %ld", time1.epoch_time);
    printf("\nİkinci zamanin Epoch değeri: %ld", time2.epoch_time);
    printf("\nZaman farki (saniye cinsinden): %.0f\n", diff_seconds);
    
    return 0;
}


