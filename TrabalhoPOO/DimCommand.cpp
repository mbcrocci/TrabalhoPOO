#include "DimCommand.h"



DimCommand::DimCommand ( World& w, int wd, int h) : world_(w), width_(wd), height_(h)
{}


DimCommand::~DimCommand ()
{}

void DimCommand::execute ()
{
	world_.setWorldDim ( width_, height_ );
}
