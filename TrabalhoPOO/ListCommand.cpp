#include "ListCommand.h"


ListCommand::ListCommand ()
{}


ListCommand::ListCommand ( World & w) : world_(w)
{}

ListCommand::~ListCommand ()
{}

void ListCommand::execute ()
{
	world_.list_all_entities ();
}
