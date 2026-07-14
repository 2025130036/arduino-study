2026-07-14


<img width="1080" height="1440" alt="image" src="https://github.com/user-attachments/assets/7da8c162-e3b7-4b76-80ff-be20f13cb3c9" />


<img width="1080" height="1440" alt="image" src="https://github.com/user-attachments/assets/4aa32d13-3200-4a81-abb8-0cea9f62d1f7" />


<img width="1080" height="1440" alt="image" src="https://github.com/user-attachments/assets/8df1a3bd-6176-4dad-a26a-19db4d0e47bd" />

LED 캐소드는 가장 긴쪽을 그라운드에 연결하고, 가장 긴 쪽을 왼쪽 2번째로 오게 했을 때 왼쪽부터 R, G, B이다.

만약 공통양극방식(애노드)을 사용하게 된다면 가장긴쪽을 5V에 연결하고, digitalWrite에서 HIGH인것을 LOW로, LOW인것을 HIGH로 하고 analogWrite에서 255인것을 0으로, 0인 것을 255, 85인것을 170으로... 등등 해서 바꿔주면 된다.
