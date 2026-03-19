# 과제 3: 분수 ADT 구현 및 직사각형 넓이/둘레 계산기

## 1. 분수 (Fraction) ADT
* **데이터 (Data Object):**
  * `num`: 분자 (정수)
  * `den`: 분모 (정수, 0은 안 됨)
* **연산 (Operations):**
  * `parse_fraction`: 문자열("A/B", "A.B", "A")을 분수 자료형으로 변환
  * `print_fraction`: 분수를 "A/B" 형태로 출력 (분모가 1이면 정수 "A"로 출력)
  * `reduce_fraction`: 기약분수로 약분
  * `add_fraction`, `sub_fraction`, `mul_fraction`, `div_fraction`: 사칙연산 수행 후 기약분수로 반환

## 2. GCD & LCM 알고리즘
* **GCD (최대공약수):** 유클리드 호제법 (나머지가 0이 될 때까지 나누기)
* **LCM (최소공배수):** 두 수의 곱을 최대공약수로 나누기 `(A * B) / GCD`
