# 🎮 회전 발판과 움직이는 장애물

여섯 번째 실습 과제를 풀어보았습니다!

## 사용한 기술
<img alt="C++" src ="https://img.shields.io/badge/C++-00599C.svg?&style=for-the-badge&logo=cplusplus&logoColor=White"/>

## 1️⃣ 필수 기능
### **서로 다른 Actor 클래스 2개 이상 구현**

- 각각 **StaticMeshComponent**를 가지며, 맵에 배치 가능한 형태여야 합니다.
- 두 클래스는 서로 **다른 동작 로직**을 수행해야 합니다.
### **Tick 함수 기반 동적 Transform 변경**

- **회전 기능**
    - `Tick(float DeltaTime)`에서 `AddActorLocalRotation()` 사용하여 **매 프레임 회전** 처리
- **이동 기능**
    - `Tick(float DeltaTime)`에서 위치를 변경하여 **왕복 이동** 구현
    - `MoveSpeed`, `MaxRange`, `StartLocation` 등을 고려해 일정 범위를 벗어나면 이동 방향을 반전시키는 로직 구성
- **프레임 독립성**
    - 이동/회전 시 반드시 `DeltaTime`을 활용하여 하드웨어 성능에 관계없이 일정한 움직임을 보장해야 합니다.
 
### **리플렉션 적용**

- 주요 변수 (회전 속도, 이동 속도, 이동 범위 등)를 `UPROPERTY`로 선언하여 **에디터에서 조정 가능**하게 만들어야 합니다.
- `EditAnywhere`, `BlueprintReadWrite`, `Category` 등을 적절히 활용하여 **Details 패널**에서 편집 가능하게 만듭니다.
- 플레이 중 Details 패널에서 값 변경 시 **즉시 반영**되는지 확인합니다.

## 2️⃣ 도전 기능
### **타이머 시스템 활용 (난이도 중상)**

- **타이머 활용**
    - `FTimerHandle`과 `GetWorld()->GetTimerManager().SetTimer(...)`를 사용해 특정 시간 후 또는 주기적으로 함수를 호출합니다.
    - 매 프레임 호출(`Tick`)보다 **효율적인 퍼포먼스**를 제공합니다.
- **시간 기반 로직 구현**
    - 일정 시간 후 액터터가 사라지는 로직을 추가합니다.

### **랜덤 퍼즐 생성 (난이도 상)**

- **동적 스폰**
    - 게임 시작 시 `SpawnActor`를 통해 **회전/이동 액터**을 **임의 좌표**에 여러 개 배치합니다.
    - **랜덤 스테이지의** 기초 개념을 체험할 수 있습니다.
- **랜덤 속성 부여**
    - 회전/이동 속도, 이동 범위를 `FMath::RandRange`로 생성하여 매번 다른 퍼즐 코스를 구성합니다.
