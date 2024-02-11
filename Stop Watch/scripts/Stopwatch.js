// @ts-nocheck
let hour = 0;
let minute = 0;
let second = 0;
let intervalId;
let flag = true;

document.querySelector('.js-start-button').addEventListener('click', () => {
    if(flag) {
        startClock();
        flag = false;
    }
});

document.querySelector('.js-stop-button').addEventListener('click', () => {
    clearInterval(intervalId);
    flag = true;
});
document.querySelector('.js-reset-button').addEventListener('click', () => {
    hour = minute = second = 0;
    document.querySelector('.js-timer')
    .innerHTML = '00:00:00';
});

function startClock() {

    intervalId = setInterval(() => {
        second++;
        if(second == 60) {
            minute++;
            second = 0;
        }
        if(minute == 60) {
            hour++;
            minute = 0;
            second = 0;
        }

        let hourString = hour;
        let minuteString = minute;
        let secondString = second; 

        if(hour < 10) {
            hourString = "0" + hourString;
        }
        if(minute < 10) {
            minuteString = "0" + minuteString;
        }
        if(second < 10) {
            secondString = "0" + secondString;
        }
        document.querySelector('.js-timer')
        .innerHTML = `${hourString}:${minuteString}:${secondString}`;
    }, 1000);

}