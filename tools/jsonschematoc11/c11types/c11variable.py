from c11type import C11Type
from c11typebool import C11TypeBool
from c11typeinteger import C11TypeInteger
from c11typenumber import C11TypeNumber
from c11typestring import C11TypeString
from c11typearray import C11TypeArray
from c11typenone import C11TypeNone

class C11Variable(object):
    def __init__(self, name, schemaValue):
        self.schemaValue = schemaValue
        self.c11Type = C11TypeNone()
        self.name = name
        self.comment = None
        if u'description' in schemaValue:
            self.comment = schemaValue[u'description']

    def revise(self, c11Types):
        if u'type' in self.schemaValue:
            schemaValueType = self.schemaValue[u'type']
        elif u'$ref' in self.schemaValue:
            schemaValueType = self.schemaValue[u'$ref']
        elif u'allOf' in self.schemaValue and len(self.schemaValue[u'allOf']) > 0 and u'$ref' in self.schemaValue[u'allOf'][0]:
            schemaValueType = self.schemaValue[u'allOf'][0][u'$ref']
        elif u'anyOf' in self.schemaValue and len(self.schemaValue[u'anyOf']) > 0:
            for schemaValueAnyOf in self.schemaValue[u'anyOf']:
                if u'type' not in schemaValueAnyOf:
                    continue
                schemaValueType = schemaValueAnyOf[u'type']
                break
        else:
            return (0, None)
        if schemaValueType == u'bool' or schemaValueType == u'boolean':
            self.c11Type = C11TypeBool()
        elif schemaValueType == u'integer':
            self.c11Type = C11TypeInteger()
        elif schemaValueType == u'number':
            self.c11Type = C11TypeNumber()
        elif schemaValueType == u'string':
            self.c11Type = C11TypeString()
        elif schemaValueType == u'array':
            self.c11Type = C11TypeArray()
            self.c11Type.setItemSchema(self.schemaValue)
        else:
            if schemaValueType not in c11Types:
                if u'additionalProperties' in self.schemaValue:
                    schemaValueAdditionalProperties = self.schemaValue[u'additionalProperties']
                    if u'$ref' in schemaValueAdditionalProperties:
                        schemaValueType = schemaValueAdditionalProperties[u'$ref']
            if schemaValueType in c11Types:
                self.c11Type = c11Types[schemaValueType]
            else:
                self.c11Type = C11TypeNone()
        self.c11Type.revise(c11Types)
        return (0, None)

    def hasComment(self):
        return self.comment != None

    def codeComment(self):
        return self.comment

    def codeDeclare(self):
        return u'%s %s' % (self.c11Type.codeTypeName(withDeclare=True, asVariable=True), self.name)
