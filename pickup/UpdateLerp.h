#pragma once
#include "memory"

template<typename T>
void UpdateLerp(std::unique_ptr<T>& Lerp)
{
	if (!Lerp) return;

	Lerp->Update();

	if (Lerp->IsFinished()) {
		Lerp.reset();
	}
}