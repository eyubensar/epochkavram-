#include <stdio.h>
#include <time.h>

struct Date {
    int year;
    int month;
    int day;
};

// Tarihi epoch zamanina ceviren fonksiyon
time_t convertToEpoch(struct Date date) {
    struct tm time_info = {0};
    time_info.tm_year = date.year - 1900;  // Yil 1900'dan itibaren sayilir
    time_info.tm_mon = date.month - 1;     // Ay 0-11 araliginda tutulur
    time_info.tm_mday = date.day;
    return mktime(&time_info);
}

int main() {
    struct Date birthDate;
    time_t currentTime;
    time(&currentTime); // Su anki zamani al

    printf("Dogum tarihinizi girin (YYYY MM DD): ");
    scanf("%d %d %d", &birthDate.year, &birthDate.month, &birthDate.day);
    
    // Kullanicinin dogum tarihini epoch zamanina cevirme
    time_t birthEpoch = convertToEpoch(birthDate);
    
    // Yas hesaplama
    double secondsLived = difftime(currentTime, birthEpoch);
    int yearsLived = secondsLived / (60 * 60 * 24 * 365);
    
    printf("\nYasiniz: %d yil\n", yearsLived);
    return 0;
}