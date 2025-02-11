#include <stdio.h>
#include <time.h>

struct MatchTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

// Mac zamanini epoch zamanina ceviren fonksiyon
time_t convertToEpoch(struct MatchTime match) {
    struct tm time_info = {0};
    time_info.tm_year = match.year - 1900;
    time_info.tm_mon = match.month - 1;
    time_info.tm_mday = match.day;
    time_info.tm_hour = match.hour;
    time_info.tm_min = match.minute;
    return mktime(&time_info);
}

int main() {
    struct MatchTime matchStart, matchEnd;
    
    printf("Voleybol macinin baslangic zamanini girin (YYYY MM DD HH MM): ");
    scanf("%d %d %d %d %d", &matchStart.year, &matchStart.month, &matchStart.day, &matchStart.hour, &matchStart.minute);
    
    printf("Voleybol macinin bitis zamanini girin (YYYY MM DD HH MM): ");
    scanf("%d %d %d %d %d", &matchEnd.year, &matchEnd.month, &matchEnd.day, &matchEnd.hour, &matchEnd.minute);
    
    // Mac baslangic ve bitis zamanlarini epoch zamanina cevirme
    time_t matchStartEpoch = convertToEpoch(matchStart);
    time_t matchEndEpoch = convertToEpoch(matchEnd);
    
    // Gecen sure hesaplama
    double secondsPassed = difftime(matchEndEpoch, matchStartEpoch);
    int minutesPassed = secondsPassed / 60;
    int hoursPassed = minutesPassed / 60;
    int daysPassed = hoursPassed / 24;
    
    printf("\nBaslangic epoch zamani: %ld\n", matchStartEpoch);
    printf("Bitis epoch zamani: %ld\n", matchEndEpoch);
    printf("Mac suresi: %d gun, %d saat, %d dakika\n", daysPassed, hoursPassed % 24, minutesPassed % 60);
    
    return 0;
}