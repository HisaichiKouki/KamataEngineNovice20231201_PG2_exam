#pragma once

namespace Easing {
	float	Lerp(float start, float end, float t);

	/// <summary>
	/// easing無し
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float Linear(float t, float totaltime, float min, float max);

	/// <summary>
	/// 1番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InSine(float t, float totaltime, float min, float max);
	/// <summary>
	/// 1番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float OutSine(float t, float totaltime, float min, float max);
	/// <summary>
	/// 1番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InOutSine(float t, float totaltime, float min, float max);

	/// <summary>
	/// 2番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InQuad(float t, float totaltime, float min, float max);
	/// <summary>
	/// 2番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float OutQuad(float t, float totaltime, float min, float max);
	/// <summary>
	/// 2番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InOutQuad(float t, float totaltime, float min, float max);

	/// <summary>
	/// 3番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InCubic(float t, float totaltime, float min, float max);
	/// <summary>
	/// 3番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float OutCubic(float t, float totaltime, float min, float max);
	/// <summary>
	/// 3番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InOutCubic(float t, float totaltime, float min, float max);

	/// <summary>
	/// 4番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InQuart(float t, float totaltime, float min, float max);
	/// <summary>
	/// 4番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float OutQuart(float t, float totaltime, float min, float max);
	/// <summary>
	/// 4番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InOutQuart(float t, float totaltime, float min, float max);

	/// <summary>
	/// 5番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InQuint(float t, float totaltime, float min, float max);
	/// <summary>
	/// 5番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float OutQuint(float t, float totaltime, float min, float max);
	/// <summary>
	/// 5番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InOutQuint(float t, float totaltime, float min, float max);

	/// <summary>
	/// 6番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InExpo(float t, float totaltime, float min, float max);
	/// <summary>
	/// 6番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float OutExpo(float t, float totaltime, float min, float max);
	/// <summary>
	/// 6番目に緩やかなeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InOutExpo(float t, float totaltime, float min, float max);

	/// <summary>
	/// 初速が早いeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InCirc(float t, float totaltime, float min, float max);
	/// <summary>
	/// 初速が早いeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float OutCirc(float t, float totaltime, float min, float max);
	/// <summary>
	/// 初速が早いeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InOutCirc(float t, float totaltime, float min, float max);

	/// <summary>
	/// 勢いよく飛び出して戻る動き
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータルの時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <param name="s">飛び出す割合。0.1fで1%10で100%</param>
	/// <returns></returns>
	float InBack(float t, float totaltime, float min, float max,float s);
	/// <summary>
	/// 勢いよく飛び出して戻る動き
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータルの時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <param name="s">飛び出す割合。0.1fで1%10で100%</param>
	/// <returns></returns>
	float OutBack(float t, float totaltime, float min, float max, float s);
	/// <summary>
	/// 勢いよく飛び出して戻る動き
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータルの時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <param name="s">飛び出す割合。0.1fで1%10で100%</param>
	/// <returns></returns>
	float InOutBack(float t, float totaltime, float min, float max, float s);

	/// <summary>
	/// 弾性的にポジションを移動する
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータルの時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <param name="amplitude">振幅。デフォルトは1.0f</param>
	/// <param name="period">周期デフォルトは0.3f</param>
	/// <returns></returns>
	float InElastic(float t, float totaltime, float min, float max, float amplitude, float period);
	/// <summary>
	/// 弾性的にポジションを移動する
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータルの時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <param name="amplitude">振幅。デフォルトは1.0f</param>
	/// <param name="period">周期デフォルトは0.3f</param>
	/// <returns></returns>
	float OutElastic(float t, float totaltime,float min,float max, float amplitude, float period);
	/// <summary>
	/// 弾性的にポジションを移動する
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータルの時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <param name="amplitude">振幅。デフォルトは1.0f</param>
	/// <param name="period">周期デフォルトは0.3f</param>
	/// <returns></returns>
	float InOutElastic(float t, float totaltime, float min, float max, float amplitude, float period);

	/// <summary>
	/// バウンドするeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InBounce(float t, float totaltime, float min, float max);
	/// <summary>
	/// バウンドするeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float OutBounce(float t, float totaltime, float min, float max);
	/// <summary>
	/// バウンドするeasing
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータル時間</param>
	/// <param name="min">開始地点</param>
	/// <param name="max">停止地点</param>
	/// <returns></returns>
	float InOutBounce(float t, float totaltime, float min, float max);

	/// <summary>
	/// 弾性のある動き。振幅と周期のみ
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータルの時間</param>
	/// <param name="amplitude">振幅。デフォルトは1.0f</param>
	/// <param name="period">周期デフォルトは0.3f</param>
	/// <returns></returns>
	float InElasticAmplitude(float t, float totaltime, float amplitude, float period);
	/// <summary>
	/// 弾性のある動き。振幅と周期のみ
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータルの時間</param>
	/// <param name="amplitude">振幅。デフォルトは1.0f</param>
	/// <param name="period">周期デフォルトは0.3f</param>
	/// <returns></returns>
	float OutElasticAmplitude(float t, float totaltime, float amplitude, float period);
	/// <summary>
	/// 弾性のある動き。振幅と周期のみ
	/// </summary>
	/// <param name="t">今の時間</param>
	/// <param name="totaltime">トータルの時間</param>
	/// <param name="amplitude">振幅。デフォルトは1.0f</param>
	/// <param name="period">周期デフォルトは0.3f</param>
	/// <returns></returns>
	float InOutElasticAmplitude(float t, float totaltime, float amplitude, float period);

}