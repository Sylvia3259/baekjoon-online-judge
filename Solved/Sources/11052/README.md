# 카드 구매하기 [🔗](https://www.acmicpc.net/problem/11052)

## 문제
<p>요즘 민규네 동네에서는 스타트링크에서 만든 PS카드를 모으는 것이 유행이다.</p>
<p>PS카드는 PS(Problem Solving)분야에서 유명한 사람들의 아이디와 얼굴이 적혀있는 카드이다. 각각의 카드에는 등급을 나타내는 색이 칠해져 있고, 다음과 같이 8가지가 있다.</p>
<ul>
<li><span class="user-legendary"><span class="user-legendary-first-letter">전</span>설카드</span></li>
<li><span class="user-red">레드카드</span></li>
<li><span class="user-orange">오렌지카드</span></li>
<li><span class="user-violet">퍼플카드</span></li>
<li><span class="user-blue">블루카드</span></li>
<li><span class="user-cyan">청록카드</span></li>
<li><span class="user-green">그린카드</span></li>
<li><span class="user-gray">그레이카드</span></li>
</ul>
<p>카드는 카드팩의 형태로만 구매할 수 있고, 카드팩의 종류는 카드 1개가 포함된 카드팩, 카드 2개가 포함된 카드팩, ... 카드 N개가 포함된 카드팩과 같이 총 N가지가 존재한다.</p>
<p>민규는 카드의 개수가 적은 팩이더라도 가격이 비싸면 높은 등급의 카드가 많이 들어있을 것이라는 미신을 믿고 있다. 따라서, 민규는 돈을 최대한 많이 지불해서 카드 N개 구매하려고 한다. 카드가 i개 포함된 카드팩의 가격은 P<sub>i</sub>원이다.</p>
<p>예를 들어, 카드팩이 총 4가지 종류가 있고, P<sub>1</sub> = 1, P<sub>2</sub> = 5, P<sub>3</sub> = 6, P<sub>4</sub> = 7인 경우에 민규가 카드 4개를 갖기 위해 지불해야 하는 금액의 최댓값은 10원이다. 2개 들어있는 카드팩을 2번 사면 된다.</p>
<p>P<sub>1</sub> = 5, P<sub>2</sub> = 2, P<sub>3</sub> = 8, P<sub>4</sub> = 10인 경우에는 카드가 1개 들어있는 카드팩을 4번 사면 20원이고, 이 경우가 민규가 지불해야 하는 금액의 최댓값이다.</p>
<p>마지막으로, P<sub>1</sub> = 3, P<sub>2</sub> = 5, P<sub>3</sub> = 15, P<sub>4</sub> = 16인 경우에는 3개 들어있는 카드팩과 1개 들어있는 카드팩을 구매해 18원을 지불하는 것이 최댓값이다.</p>
<p>카드 팩의 가격이 주어졌을 때, N개의 카드를 구매하기 위해 민규가 지불해야 하는 금액의 최댓값을 구하는 프로그램을 작성하시오. N개보다 많은 개수의 카드를 산 다음, 나머지 카드를 버려서 N개를 만드는 것은 불가능하다. 즉, 구매한 카드팩에 포함되어 있는 카드 개수의 합은 N과 같아야 한다.</p>

## 입력
<p>첫째 줄에 민규가 구매하려고 하는 카드의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)</p>
<p>둘째 줄에는 P<sub>i</sub>가 P<sub>1</sub>부터 P<sub>N</sub>까지 순서대로 주어진다. (1 ≤ P<sub>i</sub> ≤ 10,000)</p>

## 출력
<p>첫째 줄에 민규가 카드 N개를 갖기 위해 지불해야 하는 금액의 최댓값을 출력한다.</p>

## 힌트
<p><img alt="" src="https://upload.acmicpc.net/ffb63d22-5554-46ca-8e8b-7f3482d518b7/-/resize/600x/" style="width: 300px; height: 409px;"><img alt="" src="https://upload.acmicpc.net/d7c63a92-8f10-4546-bbdd-208242610cd5/-/resize/600x/" style="width: 300px; height: 409px;"/><img alt="" src="https://upload.acmicpc.net/564c40e9-47d1-48fa-bf74-d494f4e0a2da/-/resize/600x/" style="width: 300px; height: 409px;"/><img alt="" src="https://upload.acmicpc.net/6558125f-de39-4f5a-821b-a28367ead81d/-/resize/600x/" style="width: 300px; height: 409px;"/><img alt="" src="https://upload.acmicpc.net/0e1ddc25-a3b4-441c-9461-4bb97a1d5b4b/-/resize/600x/" style="width: 300px; height: 409px;"/><img alt="" src="https://upload.acmicpc.net/9a88e5aa-c6de-4b53-bd64-ef7de69dd1ec/-/resize/600x/" style="width: 300px; height: 409px;"/><img alt="" src="https://upload.acmicpc.net/b626cbbd-81ac-43d5-8ebc-ddb990f1e333/-/resize/600x/" style="width: 300px; height: 409px;"/></img></p>

