#pragma once
#include "Block.h"
#include "IColorManager.h"
#include "EResult.h"

namespace TetrisAPI
{
	class Grid
	{
	public:
		Grid(IColorManager* colorManager);

		int ClearLastLines();
		void Rotate();
		void Move(const Position& pos);
		void MoveDown();
		bool BlockStoppedMoving() const;
		void SpawnBlock(const Block& block);
	private:
		bool LastLineFull() const;
		void ClearLastLine();
		EResult TrySpawnCurrentBlock(const Position& offset) const;
		EResult TrySpawn(const Position& pos) const;
		void SpawnCurrentBlock();
		void RemoveCurrentBlock();
		void MoveDownCurrentBlock();
		bool IsPositionEmpty(const Position& pos) const;
		bool IsPositionInGrid(const Position& pos) const;

		Color& operator[](const Position& pos);
		const Color& operator[](const Position& pos) const;
	private:
		std::vector<std::vector<Color>> m_grid;
		Block m_currentBlock;
		Position m_currentBlockOffset;
		bool m_blockCanMove;

		const Color m_emptyCellColor;

		static inline const int WIDTH = 15;
		static inline const int HEIGHT = 15;
	};
}

